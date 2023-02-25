SELECT ai.NAME, ai.DATETIME
FROM ANIMAL_INS ai LEFT OUTER JOIN ANIMAL_OUTS ao ON ai.animal_id = ao.animal_id
WHERE ao.animal_id IS NULL
ORDER BY ai.datetime
LIMIT 3;