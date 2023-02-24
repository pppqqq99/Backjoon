-- 코드를 입력하세요
SELECT animal_ins.animal_id AS ANIMAL_ID, animal_ins.name AS NAME
FROM animal_ins, animal_outs
WHERE animal_ins.animal_id = animal_outs.animal_id AND animal_ins.datetime > animal_outs.datetime
ORDER BY animal_ins.datetime;