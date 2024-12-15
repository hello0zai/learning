import sys
import requests
from PySide6.QtWidgets import (
    QApplication, QTableWidget, QTableWidgetItem, QVBoxLayout, QMainWindow,
    QWidget, QPushButton, QHBoxLayout, QLabel
)
from PySide6.QtCore import QTimer
from sqlalchemy import create_engine, Column, Integer, String
from sqlalchemy.orm import declarative_base, sessionmaker

# SQLAlchemy setup
# DATABASE_URL = "postgresql+psycopg2://user:password@localhost/comments_db"  # Replace with your credentials
DATABASE_URL = "postgresql+psycopg2://postgres:postgres@192.168.2.200:5432/comments_db" 
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
        self.setWindowTitle("Paginated Comments Table")
        self.setGeometry(100, 100, 1000, 600)

        # Central widget and layout
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        self.layout = QVBoxLayout(central_widget)

        # Table widget
        self.table = QTableWidget()
        self.layout.addWidget(self.table)

        # Pagination controls
        self.pagination_layout = QHBoxLayout()
        self.previous_button = QPushButton("Previous")
        self.next_button = QPushButton("Next")
        self.page_label = QLabel("Page: 1")
        self.previous_button.clicked.connect(self.previous_page)
        self.next_button.clicked.connect(self.next_page)
        self.pagination_layout.addWidget(self.previous_button)
        self.pagination_layout.addWidget(self.page_label)
        self.pagination_layout.addWidget(self.next_button)
        self.layout.addLayout(self.pagination_layout)

        # Save button
        self.save_button = QPushButton("Save to Database")
        self.save_button.clicked.connect(self.save_to_database)
        self.layout.addWidget(self.save_button)

        # Timer for periodic updates
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.fetch_data_from_api)
        self.timer.start(30 * 1000)  # 30 seconds

        # Initialize data and pagination
        self.data = []
        self.current_page = 1
        self.items_per_page = 30

        # Initial data fetch
        self.fetch_data_from_api()

    def fetch_data_from_api(self):
        try:
            # Fetch data from API
            url = "https://jsonplaceholder.typicode.com/comments"
            response = requests.get(url)
            response.raise_for_status()
            self.data = response.json()
            self.current_page = 1  # Reset to the first page
            self.populate_table()
        except Exception as e:
            print(f"Error fetching data from API: {e}")

    def populate_table(self):
        # Get data for the current page
        start_index = (self.current_page - 1) * self.items_per_page
        end_index = start_index + self.items_per_page
        page_data = self.data[start_index:end_index]

        # Populate table
        self.table.setRowCount(len(page_data))
        self.table.setColumnCount(5)
        self.table.setHorizontalHeaderLabels(["Post ID", "ID", "Name", "Email", "Body"])

        for row_index, row_data in enumerate(page_data):
            self.table.setItem(row_index, 0, QTableWidgetItem(str(row_data["postId"])))
            self.table.setItem(row_index, 1, QTableWidgetItem(str(row_data["id"])))
            self.table.setItem(row_index, 2, QTableWidgetItem(row_data["name"]))
            self.table.setItem(row_index, 3, QTableWidgetItem(row_data["email"]))
            self.table.setItem(row_index, 4, QTableWidgetItem(row_data["body"]))

        # Update pagination label
        self.page_label.setText(f"Page: {self.current_page}")

        # Resize columns
        self.table.resizeColumnsToContents()

    def next_page(self):
        if self.current_page * self.items_per_page < len(self.data):
            self.current_page += 1
            self.populate_table()

    def previous_page(self):
        if self.current_page > 1:
            self.current_page -= 1
            self.populate_table()

    def save_to_database(self):
        try:
            # Save data from table to PostgreSQL
            session = Session()

            # Clear existing records for simplicity
            session.query(Comment).delete()

            # Iterate over all pages to save data
            for page in range(1, (len(self.data) - 1) // self.items_per_page + 2):
                start_index = (page - 1) * self.items_per_page
                end_index = start_index + self.items_per_page
                page_data = self.data[start_index:end_index]

                for row_data in page_data:
                    comment = Comment(
                        post_id=row_data["postId"],
                        id=row_data["id"],
                        name=row_data["name"],
                        email=row_data["email"],
                        body=row_data["body"],
                    )
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
