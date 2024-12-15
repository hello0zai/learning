import sys
import requests
from PySide6.QtWidgets import (
    QApplication,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QMainWindow,
    QWidget,
    QScrollArea,
)
from PySide6.QtCore import QTimer


class ScrollableTableApp(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Scrollable Table from API")
        self.setGeometry(100, 100, 800, 600)

        # Central widget and scroll area
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        layout = QVBoxLayout(central_widget)

        # Scrollable table widget
        self.scroll_area = QScrollArea()
        self.table = QTableWidget()
        self.scroll_area.setWidgetResizable(True)
        self.scroll_area.setWidget(self.table)
        layout.addWidget(self.scroll_area)

        # Timer for periodic updates
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.populate_table)
        self.timer.start(30 * 1000)  # 30 seconds in milliseconds

        # Initial population of the table
        self.populate_table()

    def populate_table(self):
        try:
            # Fetch data from the API
            url = "https://jsonplaceholder.typicode.com/comments"
            response = requests.get(url)
            response.raise_for_status()
            data = response.json()

            # Update table dimensions
            self.table.setRowCount(len(data))
            self.table.setColumnCount(5)  # Display selected fields: ID, Name, Email, Body
            self.table.setHorizontalHeaderLabels(["Post ID", "ID", "Name", "Email", "Body"])

            # Populate table with new data
            for row_index, row_data in enumerate(data):
                self.table.setItem(row_index, 0, QTableWidgetItem(str(row_data["postId"])))
                self.table.setItem(row_index, 1, QTableWidgetItem(str(row_data["id"])))
                self.table.setItem(row_index, 2, QTableWidgetItem(row_data["name"]))
                self.table.setItem(row_index, 3, QTableWidgetItem(row_data["email"]))
                self.table.setItem(row_index, 4, QTableWidgetItem(row_data["body"]))

            # Resize columns for better readability
            self.table.resizeColumnsToContents()
        except Exception as e:
            print(f"Error fetching data: {e}")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = ScrollableTableApp()
    window.show()
    sys.exit(app.exec())
