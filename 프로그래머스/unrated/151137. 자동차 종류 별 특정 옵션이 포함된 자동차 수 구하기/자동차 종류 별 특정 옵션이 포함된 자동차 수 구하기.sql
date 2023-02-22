-- 코드를 입력하세요
SELECT CAR_TYPE, count(car_id) AS 'CARS'
FROM CAR_RENTAL_COMPANY_CAR
WHERE options like '%통풍시트%' or options like '%열선시트%' or options like '%가죽시트%'
GROUP BY car_type
ORDER BY car_type;