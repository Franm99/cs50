import csv

with open('favorites.csv', 'r') as f:
    reader = csv.DictReader(f)
    next(reader)
    
    counts = {}
    for row in reader:
        fav = row["language"]
        if fav in counts:
            counts[fav] += 1
        else:
            counts[fav] = 1
    
    [print(f"{fav}: {counts[fav]}") for fav in counts]    