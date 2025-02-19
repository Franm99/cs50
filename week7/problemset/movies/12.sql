SELECT title FROM movies WHERE id IN 
    (SELECT DISTINCT(movie_id) FROM stars WHERE movie_id IN 
        (SELECT movie_id FROM stars WHERE person_id = 
        (SELECT id FROM people WHERE name = 'Jennifer Lawrence')) 
        AND movie_id IN 
        (SELECT movie_id FROM stars WHERE person_id = 
        (SELECT id FROM people WHERE name = 'Bradley Cooper')));


--
SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Jennifer Lawrence') INTERSECT SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Bradley Cooper'))