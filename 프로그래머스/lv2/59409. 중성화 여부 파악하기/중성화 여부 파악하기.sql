SELECT ANIMAL_ID, NAME, IF(sex_upon_intake like 'Neutered%' or sex_upon_intake like 'Spayed%', 'O', 'X') AS '중성화'
FROM ANIMAL_INS
ORDER BY animal_id;