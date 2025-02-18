# Doctors-patients
This C++ application opens a new window for each doctor and lists its patients. Each patient is allocated to a doctor according to the doctor's name and specialization, or if a patient is undiagnosed it will be listed in every doctor's window. The application allows the user to: filter diagnosed patients, add patients and update patients.

## GUI
The GUI is made using the QT library in QT designer. On startup, the application will open a new window for every doctor.\
![image](https://github.com/user-attachments/assets/e94d857a-e5c5-4ea4-8f76-27164306fd6f)
![image](https://github.com/user-attachments/assets/4ca1a2f1-a928-46ee-af9e-b972aaaf930e)


## Observer design pattern
The Observer design pattern in this application ensures that whenever a patient is updated, all relevant doctor windows are notified of the change. This is how it works:
- Repository as a Subject: Repository inherits from Subject, which maintains a list of Observer* (doctor windows). The repository stores patients and doctors and can modify them.
- Observers (Doctor Windows): Each doctor's window registers itself as an Observer to the Repository using addObserver(). These windows implement the update() method to refresh their patient lists when notified.
- Automatic Updates via notify(): When a patient is added or updated (addPatient(), updatePatient()), notify() is called, which loops through all observers and calls their update() method. This ensures that when a patient’s doctor or specialization changes, all doctor windows automatically reflect the updated distribution.
<\br>This setup keeps the UI in sync with the repository, ensuring real-time updates across multiple windows.

## Screenshots
### Initial windows
Each doctor has its own window and a list of patients.
![image](https://github.com/user-attachments/assets/5c30116e-e7fe-4461-9dee-36361f8de7e6)
### Filtered patients
Each doctor can see the current patients he takes care of.
![image](https://github.com/user-attachments/assets/280c4194-44d9-4ecd-88e4-4111a0441941)
### Add/Update
You can add or update a certain patient from any window and the restults will be displayed in the corresponding doctor's window.
![image](https://github.com/user-attachments/assets/c2bc56ff-a960-4641-a67e-cf68adff0305)
![image](https://github.com/user-attachments/assets/be40176e-b1c5-418c-b555-f87c0d2e86db)
