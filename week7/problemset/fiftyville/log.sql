-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description 
FROM crime_scene_reports 
WHERE description LIKE "%duck%";

-- 'Theft of the CS50 duck took place at 10:15am at the Humphrey Street 
-- bakery. Interviews were conducted today with three witnesses who were 
-- present at the time – each of their interview transcripts mentions 
-- the bakery.'

SELECT transcript 
FROM interviews 
WHERE transcript 
LIKE "%bakery%"

-- HINT 1:
/*'Sometime within ten minutes of the theft, I saw the thief get into a 
car in the bakery parking lot and drive away. If you have security 
footage from the bakery parking lot, you might want to look for cars 
that left the parking lot in that time frame.'*/
-- HINT 2:
/* "I don't know the thief's name, but it was someone I recognized. 
Earlier this morning, before I arrived at Emma's bakery, I was walking 
by the ATM on Leggett Street and saw the thief there withdrawing some 
money."
-- HINT 3:
/* 'As the thief was leaving the bakery, they called someone who talked 
to them for less than a minute. In the call, I heard the thief say that 
they were planning to take the earliest flight out of Fiftyville 
tomorrow. The thief then asked the person on the other end of the phone 
to purchase the flight ticket.'*/

SELECT hour, minute, activity, license_plate FROM bakery_security_logs WHERE (hour = 10 AND minute BETWEEN 15 AND 25) AND activity = 'exit' ORDER BY hour, minute

/*
(10, 15, 'exit', '11J91FW')
(10, 16, 'exit', '5P2BI95')
(10, 16, 'exit', 'PF37ZVK')
(10, 18, 'exit', '94KL13X')
(10, 18, 'exit', '6P58WS2')
(10, 19, 'exit', '4328GD8')
(10, 20, 'exit', 'G412CB7')
(10, 20, 'exit', '1M92998')
(10, 21, 'exit', 'L93JTIZ')
(10, 21, 'exit', 'XE95071')
(10, 23, 'exit', '322W7JE')
(10, 23, 'exit', '0NTHK55')
(10, 24, 'exit', 'IH61GO8')
(10, 25, 'exit', '8P9NEU9')
*/

SELECT account_number, amount 
FROM atm_transactions 
WHERE 
    (atm_location = 'Leggett Street') AND 
    (transaction_type = 'withdraw') AND 
    (year = 2024) AND 
    (month = 7) AND 
    (day = 28)

/*
(28500762, 48)
(28296815, 20)
(76054385, 60)
(49610011, 50)
(16153065, 80)
(25506511, 20)
(81061156, 30)
(26013199, 35)
*/

SELECT caller, receiver 
FROM phone_calls 
WHERE 
    (duration < 60) AND 
    (year = 2024) AND 
    (month = 7) AND 
    (day = 28)

/*
('(130) 555-0289', '(996) 555-8899')
('(499) 555-9472', '(892) 555-8872')
('(367) 555-5533', '(375) 555-8161')
('(499) 555-9472', '(717) 555-1342')
('(286) 555-6063', '(676) 555-6554')
('(770) 555-1861', '(725) 555-3243')
('(031) 555-6622', '(910) 555-3251')
('(826) 555-1652', '(066) 555-9701')
('(338) 555-6650', '(704) 555-2131')
*/

SELECT name, passport_number 
FROM people 
WHERE (phone_number IN (
    SELECT caller 
    FROM phone_calls 
    WHERE (duration < 60) 
    AND (year = 2024) AND (month = 7) AND (day = 28))
    ) 
AND (license_plate IN (
    SELECT license_plate 
    FROM bakery_security_logs 
    WHERE (hour = 10 AND minute BETWEEN 15 AND 25) 
    AND activity = 'exit')
    )

/*
('Sofia', 1695452385)
('Diana', 3592750733)  (X) 
('Kelsey', 8294398571)
('Bruce', 5773159633)  
*/

SELECT id FROM airports WHERE city = 'Fiftyville'

/* (8,) */

SELECT id, hour, minute FROM flights WHERE origin_airport_id = 8 
AND year = 2024 AND month = 7 AND day = 29 ORDER BY hour, minute

/* 
(36, 8, 20)  <--
(43, 9, 30)
(23, 12, 15)
(53, 15, 20)
(18, 16, 0)
*/

SELECT passport_number FROM passengers WHERE flight_id = 36

/*
(7214083635,)  <- RECEIVER
(1695452385,)  <- CALLER
(5773159633,)  <- CALLER
(1540955065,)
(8294398571,)  <- CALLER
(1988161715,)
(9878712108,)  <- CALLER
(8496433585,)
*/

SELECT passport_number FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE duration < 60 AND year = 2024 and month = 7 and day = 28)

/*
(2438825627,)
(2312901747,)
(None,)
(9029462229,)
(7834357192,)
(None,)
(3391710505,)
(None,)
(7214083635,)
*/


-- 



