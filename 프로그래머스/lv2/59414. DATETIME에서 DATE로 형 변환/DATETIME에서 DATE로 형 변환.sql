SELECT animal_id, name, date_format(datetime, '%Y-%m-%d') AS '날짜'
FROM ANIMAL_INS
ORDER BY animal_id;

