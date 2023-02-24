-- 코드를 입력하세요
SELECT animal_ins.name AS NAME, animal_ins.datetime AS DATETIME
FROM Animal_ins LEFT OUTER JOIN Animal_outs ON animal_ins.animal_id = animal_outs.animal_id
WHERE Animal_outs.animal_id IS NULL
ORDER BY Animal_ins.datetime
LIMIT 3;