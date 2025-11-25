from django.shortcuts import render
from .firebase import ref

def sensor_data_view(request):
    # ref.get() returns a dict of entries or None
    data = ref.get() or {}
    # convert dict to list of items for ordering in template
    items = []
    for key, val in data.items():
        # val is expected to be a dict: {sensor_type, value, timestamp}
        items.append(val)
    return render(request, 'sensorapp/data.html', {'sensor_data': items})
