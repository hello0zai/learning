import sys
from PySide6.QtWidgets import (
    QApplication, QMainWindow, QVBoxLayout, QPushButton, QWidget, QListView
)
from PySide6.QtCore import QStringListModel

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Dark and Light Theme Example")
        self.resize(400, 300)

        # Main layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout()
        self.central_widget.setLayout(self.layout)

        # List view to display data
        self.list_view = QListView()
        self.layout.addWidget(self.list_view)

        # Example data
        data = ["Item 1", "Item 2", "Item 3", "Item 4"]
        self.model = QStringListModel(data)
        self.list_view.setModel(self.model)

        # Theme toggle button
        self.toggle_button = QPushButton("Switch to Dark Theme")
        self.layout.addWidget(self.toggle_button)
        self.toggle_button.clicked.connect(self.toggle_theme)

        # Start with light theme
        self.current_theme = "light"
        self.apply_theme(self.current_theme)

    def toggle_theme(self):
        # Switch between light and dark themes
        if self.current_theme == "light":
            self.current_theme = "dark"
            self.toggle_button.setText("Switch to Light Theme")
        else:
            self.current_theme = "light"
            self.toggle_button.setText("Switch to Dark Theme")
        self.apply_theme(self.current_theme)

    def apply_theme(self, theme):
        # Define dark and light theme stylesheets
        light_theme = """
        QWidget {
            background-color: #FFFFFF;
            color: #000000;
        }
        QListView {
            background-color: #F0F0F0;
            color: #000000;
        }
        QPushButton {
            background-color: #E0E0E0;
            color: #000000;
        }
        """

        dark_theme = """
        QWidget {
            background-color: #2B2B2B;
            color: #FFFFFF;
        }
        QListView {
            background-color: #3C3C3C;
            color: #FFFFFF;
        }
        QPushButton {
            background-color: #5C5C5C;
            color: #FFFFFF;
        }
        """

        # Apply the selected theme
        if theme == "light":
            self.setStyleSheet(light_theme)
        else:
            self.setStyleSheet(dark_theme)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())