-- 코드를 입력하세요
SELECT BOOK_ID, AUTHOR_NAME, date_format(published_date, '%Y-%m-%d') AS PUBLISHED_DATE
FROM Book, Author
WHERE Book.author_id = Author.author_id AND category like '경제'
ORDER BY published_date;