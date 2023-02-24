-- 코드를 입력하세요
SELECT Animal_outs.animal_id AS ANIMAL_ID, Animal_outs.name AS NAME
FROM Animal_outs LEFT OUTER JOIN Animal_ins ON Animal_outs.animal_id = Animal_ins.animal_id
WHERE Animal_ins.animal_id IS NULL
ORDER BY Animal_outs.animal_id, Animal_outs.name;