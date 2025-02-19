SELECT title FROM movies WHERE id IN 
    (SELECT movie_id FROM ratings WHERE movie_id IN 
        (SELECT movie_id FROM stars WHERE person_id = 
            (SELECT id FROM people WHERE name = 'Chadwick Boseman')) 
                ORDER BY 
                    rating DESC 
                LIMIT 5);
