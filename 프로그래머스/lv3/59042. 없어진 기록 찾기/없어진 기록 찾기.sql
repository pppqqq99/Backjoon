SELECT ao.ANIMAL_ID, ao.NAME
FROM ANIMAL_OUTS ao LEFT OUTER JOIN ANIMAL_INS ai ON ao.animal_id = ai.animal_id
WHERE ai.animal_id IS NULL
ORDER BY ai.animal_id;