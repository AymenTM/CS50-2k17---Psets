
import json

# String containing a JSON Object
people_string = '''
{
    "people": [
        {
            "name": "John Smith",
            "phone": "615-555-2374",
            "emails": ["john.smith@email.com", "john.smith@work.com"],
            "has_license": false
        },
        {
            "name": "Steve Doe",
            "phone": "262-555-9762",
            "emails": null,
            "has_license": true
        }
    ]
}
'''

data = json.loads(people_string)

print(type(data))
print(data)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

# Python Dictionary
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

json_str = json.dumps(people_container, indent=4)

print(json_str)
