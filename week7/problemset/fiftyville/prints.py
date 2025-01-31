tables = [('CREATE TABLE crime_scene_reports (\n    id INTEGER,\n    year INTEGER,\n    month INTEGER,\n    day INTEGER,\n    street TEXT,\n    description TEXT,\n    PRIMARY KEY(id)\n)',),
('CREATE TABLE interviews (\n    id INTEGER,\n    name TEXT,\n    year INTEGER,\n    month INTEGER,\n    day INTEGER,\n    transcript TEXT,\n    PRIMARY KEY(id)\n)',),
('CREATE TABLE atm_transactions (\n    id INTEGER,\n    account_number INTEGER,\n    year INTEGER,\n    month INTEGER,\n    day INTEGER,\n    atm_location TEXT,\n    transaction_type TEXT,\n    amount INTEGER,\n    PRIMARY KEY(id)\n)',),
('CREATE TABLE bank_accounts (\n    account_number INTEGER,\n    person_id INTEGER,\n    creation_year INTEGER,\n    FOREIGN KEY(person_id) REFERENCES people(id)\n)',),
('CREATE TABLE airports (\n    id INTEGER,\n    abbreviation TEXT,\n    full_name TEXT,\n    city TEXT,\n    PRIMARY KEY(id)\n)',),
('CREATE TABLE flights (\n    id INTEGER,\n    origin_airport_id INTEGER,\n    destination_airport_id INTEGER,\n    year INTEGER,\n    month INTEGER,\n    day INTEGER,\n    hour INTEGER,\n    minute INTEGER,\n    PRIMARY KEY(id),\n    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),\n    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)\n)',),
('CREATE TABLE passengers (\n    flight_id INTEGER,\n    passport_number INTEGER,\n    seat TEXT,\n    FOREIGN KEY(flight_id) REFERENCES flights(id)\n)',),
('CREATE TABLE phone_calls (\n    id INTEGER,\n    caller TEXT,\n    receiver TEXT,\n    year INTEGER,\n    month INTEGER,\n    day INTEGER,\n    duration INTEGER,\n    PRIMARY KEY(id)\n)',),
('CREATE TABLE people (\n    id INTEGER,\n    name TEXT,\n    phone_number TEXT,\n    passport_number INTEGER,\n    license_plate TEXT,\n    PRIMARY KEY(id)\n)',),
('CREATE TABLE bakery_security_logs (\n    id INTEGER,\n    year INTEGER,\n    month INTEGER,\n    day INTEGER,\n    hour INTEGER,\n    minute INTEGER,\n    activity TEXT,\n    license_plate TEXT,\n    PRIMARY KEY(id)\n)',)]


for table in tables:
    print(table[0])