SELECT HISTORY_ID, CAR_ID, date_Format(start_date, '%Y-%m-%d') AS START_DATE, date_format(end_date, '%Y-%m-%d') AS END_DATE, IF(DATEDIFF(end_date, start_date)+1 >= 30, '장기 대여', '단기 대여') AS RENT_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE START_DATE like '2022-09%'
ORDER BY history_id desc;