import sys
import requests
from PySide6.QtWidgets import (
    QApplication, QVBoxLayout, QLineEdit, QPushButton, QLabel, QMainWindow, QWidget
)

API_URL = "http://127.0.0.1:5000"

class AuthApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Auth App")
        self.setGeometry(100, 100, 300, 200)

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Email input
        self.email_input = QLineEdit()
        self.email_input.setPlaceholderText("Email")
        self.layout.addWidget(self.email_input)

        # Password input
        self.password_input = QLineEdit()
        self.password_input.setPlaceholderText("Password")
        self.password_input.setEchoMode(QLineEdit.Password)
        self.layout.addWidget(self.password_input)

        # Register button
        self.register_button = QPushButton("Register")
        self.register_button.clicked.connect(self.register)
        self.layout.addWidget(self.register_button)

        # Login button
        self.login_button = QPushButton("Login")
        self.login_button.clicked.connect(self.login)
        self.layout.addWidget(self.login_button)

        # Logout button
        self.logout_button = QPushButton("Logout")
        self.logout_button.clicked.connect(self.logout)
        self.layout.addWidget(self.logout_button)

        # Response label
        self.response_label = QLabel()
        self.layout.addWidget(self.response_label)

        self.access_token = None

    def register(self):
        email = self.email_input.text()
        password = self.password_input.text()
        response = requests.post(f"{API_URL}/register", json={"email": email, "password": password})
        self.response_label.setText(response.json().get('message'))

    def login(self):
        email = self.email_input.text()
        password = self.password_input.text()
        response = requests.post(f"{API_URL}/login", json={"email": email, "password": password})
        if response.status_code == 200:
            self.access_token = response.json().get('access_token')
            self.response_label.setText("Login successful!")
        else:
            self.response_label.setText(response.json().get('message'))

    def logout(self):
        if not self.access_token:
            self.response_label.setText("You are not logged in!")
            return

        headers = {"Authorization": f"Bearer {self.access_token}"}
        response = requests.post(f"{API_URL}/logout", headers=headers)
        if response.status_code == 200:
            self.access_token = None
            self.response_label.setText("Logout successful!")
        else:
            self.response_label.setText(response.json().get('message'))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    auth_app = AuthApp()
    auth_app.show()
    sys.exit(app.exec())
