import sys
import requests
from PySide6.QtWidgets import (
    QApplication, QTableWidget, QTableWidgetItem, QVBoxLayout, QMainWindow, QWidget, QPushButton, QHBoxLayout
)
from PySide6.QtCore import QTimer
from sqlalchemy import create_engine, Column, Integer, String, MetaData
from sqlalchemy.orm import declarative_base, sessionmaker

# SQLAlchemy setup
# DATABASE_URL = "postgresql+psycopg2://user:password@localhost/comments_db"  # Replace with your database credentials
DATABASE_URL = "postgresql+psycopg2://postgres:postgres@192.168.2.200:5432/comments_db"  # Replace with your database credentials
engine = create_engine(DATABASE_URL)
Base = declarative_base()

class Comment(Base):
    __tablename__ = "comments"
    id = Column(Integer, primary_key=True, autoincrement=True)
    post_id = Column(Integer, nullable=False)
    name = Column(String, nullable=False)
    email = Column(String, nullable=False)
    body = Column(String, nullable=False)

Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)

# PySide6 Application
class ScrollableTableApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Comments Table with Database Integration")
        self.setGeometry(100, 100, 1000, 600)

        # Central widget and layout
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        self.layout = QVBoxLayout(central_widget)

        # Table widget
        self.table = QTableWidget()
        self.layout.addWidget(self.table)

        # Save button
        self.save_button = QPushButton("Save to Database")
        self.save_button.clicked.connect(self.save_to_database)
        self.layout.addWidget(self.save_button)

        # Timer for periodic updates
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.populate_table_from_api)
        self.timer.start(30 * 1000)  # 30 seconds

        # Initial data fetch
        self.populate_table_from_api()

    def populate_table_from_api(self):
        try:
            # Fetch data from API
            url = "https://jsonplaceholder.typicode.com/comments"
            response = requests.get(url)
            response.raise_for_status()
            data = response.json()

            # Populate table with data
            self.table.setRowCount(len(data))
            self.table.setColumnCount(5)
            self.table.setHorizontalHeaderLabels(["Post ID", "ID", "Name", "Email", "Body"])

            for row_index, row_data in enumerate(data):
                self.table.setItem(row_index, 0, QTableWidgetItem(str(row_data["postId"])))
                self.table.setItem(row_index, 1, QTableWidgetItem(str(row_data["id"])))
                self.table.setItem(row_index, 2, QTableWidgetItem(row_data["name"]))
                self.table.setItem(row_index, 3, QTableWidgetItem(row_data["email"]))
                self.table.setItem(row_index, 4, QTableWidgetItem(row_data["body"]))

            # Resize columns
            self.table.resizeColumnsToContents()
        except Exception as e:
            print(f"Error fetching data from API: {e}")

    def save_to_database(self):
        try:
            # Save data from table to PostgreSQL
            session = Session()

            # Clear existing records for simplicity
            session.query(Comment).delete()

            # Iterate over table rows and save data
            for row in range(self.table.rowCount()):
                post_id = int(self.table.item(row, 0).text())
                comment_id = int(self.table.item(row, 1).text())
                name = self.table.item(row, 2).text()
                email = self.table.item(row, 3).text()
                body = self.table.item(row, 4).text()

                comment = Comment(post_id=post_id, id=comment_id, name=name, email=email, body=body)
                session.add(comment)

            session.commit()
            print("Data saved to the database successfully!")
        except Exception as e:
            print(f"Error saving to database: {e}")
        finally:
            session.close()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = ScrollableTableApp()
    window.show()
    sys.exit(app.exec())


    '''
    CREATE DATABASE comments_db;

\c comments_db;

CREATE TABLE comments (
    post_id INTEGER,
    id SERIAL PRIMARY KEY,
    name TEXT,
    email TEXT,
    body TEXT
);
    '''