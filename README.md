# Hospital Patient Record System

A console-based Hospital Patient Record System developed in C that manages patient information using binary file handling. The application provides basic CRUD (Create, Read, Update, Delete) operations for maintaining hospital records efficiently.

---

## Features

- Add New Patient Records
- View All Patient Records
- Search Patient by ID
- Update Existing Patient Details
- Delete Patient Records
- Binary File Storage
- Menu-Driven Interface
- Persistent Data Storage

---

## Technologies Used

- C Programming
- Structures
- File Handling
- Binary Files
- Standard C Library

---

## Data Stored

Each patient record contains:

- Patient ID
- Name
- Age
- Disease

---

## Operations Supported

| Operation | Description |
|-----------|-------------|
| Add Patient | Store a new patient record |
| View Patients | Display all patient records |
| Search Patient | Search a patient using Patient ID |
| Update Patient | Modify an existing patient record |
| Delete Patient | Remove a patient record |
| Exit | Close the application |

---

## Menu

```text
====== HOSPITAL PATIENT RECORD SYSTEM ======

1. Add Patient
2. View All Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Exit
```

---

## File Storage

Patient records are stored in a binary file:

```text
patients.dat
```

Temporary file used during deletion:

```text
temp.dat
```

---

## Compilation

```bash
gcc hospital_patient_record.c -o hospital_patient_record
```

---

## Execution

Linux/macOS:

```bash
./hospital_patient_record
```

Windows (MinGW):

```bash
hospital_patient_record.exe
```

---

## Sample Output

```text
====== HOSPITAL PATIENT RECORD SYSTEM ======

1. Add Patient
2. View All Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Exit

Enter your choice:
```

---

## Concepts Demonstrated

- Structures
- Functions
- File Handling
- Binary File Operations
- CRUD Operations
- Data Persistence
- Menu-Driven Programming

---

## Future Enhancements

- Login and Authentication System
- Doctor Information Management
- Appointment Scheduling
- Billing System
- Medicine Inventory
- Search by Name or Disease
- Data Validation
- Database Integration (MySQL/SQLite)
- Graphical User Interface

---

## Developer

**Dogiparthi Aniruth**

CMR College of Engineering & Technology (CMRCET)

---

## License

This project is licensed under the MIT License.