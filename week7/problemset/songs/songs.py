import sqlite3
import time

con = sqlite3.connect('songs.db')
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
Two tables:

songs
------------------
id INTEGER,
name TEXT,
artist_id INTEGER,
danceability REAL,
energy REAL,
key INTEGER,
loudness REAL,
speechiness REAL,
valence REAL,
tempo REAL,
duration_ms INTEGER
-------------------

artists
------------------
id INTEGER,
name TEXT
------------------
"""