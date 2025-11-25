from django.contrib import admin
from django.urls import path
from sensorapp.views import sensor_data_view

urlpatterns = [
    path('admin/', admin.site.urls),
    path('sensor-data/', sensor_data_view, name='sensor_data'),
]
