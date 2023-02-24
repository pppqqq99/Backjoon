-- 코드를 입력하세요
SELECT Animal_ins.animal_id AS 'ANIMAL_ID', Animal_ins.animal_type AS 'ANIMAL_TYPE', Animal_ins.name
FROM Animal_ins, Animal_outs
WHERE Animal_ins.animal_id = Animal_outs.animal_id AND Animal_ins.sex_upon_intake LIKE 'Intact%' AND Animal_outs.sex_upon_outcome NOT LIKE 'Intact%'
ORDER BY Animal_ins.animal_id;