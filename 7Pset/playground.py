
import json

people_container = {

    'people': [
        {
            'name': 'John Smith',
            'phone': '615-555-2374',
            'has_license': False
        },
        {
            'name': 'Steve Doe',
            'phone': '262-555-9762',
            'has_license': True
        }
    ]
}

json_data = json.dumps(people_container, indent=4)

print(json_data)
