-- 코드를 입력하세요
SELECT mp.MEMBER_NAME, rr.REVIEW_TEXT, DATE_FORMAT(rr.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM MEMBER_PROFILE mp, REST_REVIEW rr
WHERE mp.member_id = rr.member_id 
AND mp.member_id = (SELECT member_id FROM rest_review GROUP BY member_id ORDER BY count(*) DESC LIMIT 1)
ORDER BY rr.REVIEW_DATE, rr.REVIEW_TEXT;