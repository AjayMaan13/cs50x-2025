-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28;
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28;
SELECT * FROM flights WHERE origin_airport_id =(SELECT id FROM airports WHERE city ='Fiftyville') AND month = 7 AND day = 29 AND year = 2021;
SELECT * FROM passengers WHERE flight_id = 36 AND 43;
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street';
SELECT * FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';
SELECT * FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND destination_airport_id = 4;
SELECT * FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND destination_airport_id = 1;
SELECT * FROM people WHERE id = 467400;
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passengers.passport_number = 8496433585;
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passengers.passport_number = 9878712108;
SELECT * FROM people WHERE id = 686048;
SELECT * FROM flights JOIN passengers ON flights.id = passengers.flight_id WHERE passengers.passport_number = 5773159633;
SELECT * FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND destination_airport_id = 4;
SELECT * FROM flights JOIN passengers ON flights.id = passengers.flight_id WHERE origin_airport_id = 8 AND destination_airport_id = 4 ;
SELECT * FROM flights JOIN passengers ON flights.id = passengers.flight_id WHERE origin_airport_id = 8 AND destination_airport_id = 4 AND year = 2021 AND month = 7;
SELECT * FROM flights JOIN passengers ON flights.id = passengers.flight_id WHERE origin_airport_id = 8 AND destination_airport_id = 4 AND year = 2021 AND month = 7 AND day = 29 AND id = 36
SELECT * FROM people WHERE phone_number = '(375) 555-8161';