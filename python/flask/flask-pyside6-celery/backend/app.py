from flask import Flask, request, jsonify
from flask_jwt_extended import (
    JWTManager, create_access_token, jwt_required, get_jwt_identity
)
from flask_bcrypt import Bcrypt
from sqlalchemy import create_engine, Column, Integer, String, Boolean
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

from tasks import flask_app, long_running_task, send_email


app = flask_app
# Flask and database setup
# app = Flask(__name__)
# app.config['SECRET_KEY'] = 'your_secret_key'
# app.config['JWT_SECRET_KEY'] = 'your_jwt_secret_key'
# # app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql+psycopg2://user:password@localhost/user_auth'
# app.config['SQLALCHEMY_DATABASE_URI'] = "postgresql+psycopg2://postgres:postgres@192.168.2.200:5432/comments_db"
# DATABASE_URL = "postgresql+psycopg2://postgres:postgres@192.168.2.200:5432/comments_db" 

bcrypt = Bcrypt(app)
jwt = JWTManager(app)

# Celery setup
# app.config['CELERY_BROKER_URL'] = 'redis://localhost:6379/0'
# app.config['CELERY_RESULT_BACKEND'] = 'redis://localhost:6379/0'
# app.config['CELERY_BROKER_URL'] = 'redis://:hellotest@localhost:6379/0'
# app.config['CELERY_RESULT_BACKEND'] = 'redis://:hellotest@localhost:6379/0'
# celery = Celery(app.name, broker=app.config['CELERY_BROKER_URL'])
# celery.conf.update(app.config)


# SQLAlchemy setup
Base = declarative_base()
engine = create_engine(app.config['SQLALCHEMY_DATABASE_URI'])
Session = sessionmaker(bind=engine)
db_session = Session()

class User(Base):
    __tablename__ = 'users'
    id = Column(Integer, primary_key=True)
    email = Column(String, unique=True, nullable=False)
    password = Column(String, nullable=False)
    is_active = Column(Boolean, default=False)

Base.metadata.create_all(engine)



# Routes
@app.route('/register', methods=['POST'])
def register():
    data = request.json
    email = data.get('email')
    password = data.get('password')
    if not email or not password:
        return jsonify({'message': 'Email and password are required!'}), 400

    # Check if user already exists
    if db_session.query(User).filter_by(email=email).first():
        return jsonify({'message': 'User already exists!'}), 400

    hashed_password = bcrypt.generate_password_hash(password).decode('utf-8')
    new_user = User(email=email, password=hashed_password)
    db_session.add(new_user)
    db_session.commit()

    # Send email in the background
    send_email.delay(email)

    return jsonify({'message': 'User registered successfully! Check your email for confirmation.'}), 201

@app.route('/login', methods=['POST'])
def login():
    data = request.json
    email = data.get('email')
    password = data.get('password')
    user = db_session.query(User).filter_by(email=email).first()
    if not user or not bcrypt.check_password_hash(user.password, password):
        return jsonify({'message': 'Invalid credentials!'}), 401

    # Create JWT token
    access_token = create_access_token(identity=user.email)
    return jsonify({'access_token': access_token}), 200

@app.route('/logout', methods=['POST'])
@jwt_required()
def logout():
    # Placeholder: Handle logout (e.g., invalidate tokens with a token blacklist)
    return jsonify({'message': 'Logged out successfully!'}), 200

if __name__ == '__main__':
    app.run(debug=True)
