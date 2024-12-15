import sys
import requests
from PySide6.QtWidgets import QApplication, QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget
from PySide6.QtCore import QTimer


class TableApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Dynamic Table from Flask API")
        self.setGeometry(100, 100, 600, 400)

        # Layout and Table
        self.layout = QVBoxLayout()
        self.table = QTableWidget()
        self.layout.addWidget(self.table)
        self.setLayout(self.layout)

        # Timer to refresh data every 30 seconds
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.populate_table)
        self.timer.start(30 * 1000)  # 30 seconds in milliseconds

        # Initial population of the table
        self.populate_table()

    def populate_table(self):
        try:
            # Fetch data from Flask API
            response = requests.get('http://127.0.0.1:5000/data')
            response.raise_for_status()
            data = response.json()

            # Update table dimensions
            self.table.setRowCount(len(data))
            self.table.setColumnCount(len(data[0]))
            self.table.setHorizontalHeaderLabels(data[0].keys())

            # Populate table with new data
            for row_index, row_data in enumerate(data):
                for col_index, (key, value) in enumerate(row_data.items()):
                    self.table.setItem(row_index, col_index, QTableWidgetItem(str(value)))
        except Exception as e:
            print(f"Error fetching data: {e}")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TableApp()
    window.show()
    sys.exit(app.exec())
