import sqlite3
import time

con = sqlite3.connect('movies.db')
cur = con.cursor()

query = ''
while query != 'quit':
    try:
        ts = time.time()
        cur.execute(query)
        for res in cur.fetchall():
            print(res)
        t = time.time() - ts
    except sqlite3.OperationalError as e:
        print(f"INVALID QUERY, resulted in: {e}")
    finally:
        print(f"--- took {t}s.\n")
    query = input()
    
cur.close()

"""
SELECT sql FROM sqlite_master WHERE TYPE = 'table'
====

movies
----------
id INTEGER PRIMARY KEY,
title TEXT NOT NULL,
year NUMERIC,

people
----------
id INTEGER PRIMARY KEY,
name TEXT NOT NULL,
birth NUMERIC

ratings
----------
movie_id INTEGER NOT NULL FOREIGN KEY REFERENCES movies(id),
rating REAL NOT NULL,
votes INTEGER NOT NULL

stars
----------
movie_id INTEGER NOT NULL FOREIGN KEY REFERENCES movies(id),
person_id INTEGER NOT NULL FOREIGN KEY REFERENCES people(id),


directors
----------
movie_id INTEGER NOT NULL FOREIGN KEY REFERENCES movies(id),
person_id INTEGER NOT NULL FOREIGN KEY REFERENCES people(id)
"""