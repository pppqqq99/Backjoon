SELECT mp.MEMBER_NAME, rr.REVIEW_TEXT, date_format(rr.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM MEMBER_PROFILE mp, REST_REVIEW rr
WHERE mp.member_id = rr.member_id and mp.member_id = (SELECT member_id
                                                     FROM REST_REVIEW
                                                     GROUP BY member_id
                                                     ORDER BY COUNT(*) DESC
                                                     LIMIT 1)
ORDER BY rr.REVIEW_DATE, rr.REVIEW_TEXT;