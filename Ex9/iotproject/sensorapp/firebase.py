# sensorapp/firebase.py
import firebase_admin
from firebase_admin import credentials, db
import os

# path to the service account JSON you downloaded
cred_path = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'firebase_key.json')
cred = credentials.Certificate(cred_path)

# replace the URL below with your DB URL (keep trailing slash)
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://iot-project-31da3-default-rtdb.asia-southeast1.firebasedatabase.app/'
})

# reference to the node we will use
ref = db.reference('/sensor_data')
