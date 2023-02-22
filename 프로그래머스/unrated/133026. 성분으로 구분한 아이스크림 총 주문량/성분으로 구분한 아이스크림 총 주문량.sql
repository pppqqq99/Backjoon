-- 코드를 입력하세요
SELECT INGREDIENT_TYPE, sum(total_order) AS 'TOTAL_ORDER'
FROM FIRST_HALF, ICECREAM_INFO
WHERE FIRST_HALF.flavor = ICECREAM_INFO.flavor
GROUP BY ingredient_type
ORDER BY sum(total_order);