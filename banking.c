#include <sqlite3.h>
#include <stdio.h>
// account()- This function is used to create a new account.
// transfermoney()- This function is used to transfer money to the account
// checkbalance()- This function is used to check the balance in the account.
// login()- This function is used to login into the account.
// transaction dashboard

typedef struct dbResult {
    sqlite3 *db;
    int success;
} dbResult;

int main() {}

dbResult *initDb() {
    sqlite3 *db;

    int result = sqlite3_open("mydb.db", &db);

    dbResult conn = {db, result};

    if (result != SQLITE_OK) {
        fprintf(stderr, "Cannot open DB: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return &conn;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS users ("
                      "id INTEGER PRIMARY KEY NOT NULL, "
                      "username TEXT NOT NULL, "
                      "name TEXT NOT NULL, "
                      "iban TEXT NOT NULL"
                      "); "

                      "CREATE TABLE IF NOT EXISTS accounts ("
                      "iban TEXT PRIMARY KEY NOT NULL, "
                      "owner_id INTEGER NOT NULL, "
                      "balance REAL NOT NULL, "
                      "); "

                      "CREATE TABLE IF NOT EXISTS transactions ("
                      "id TEXT PRIMARY KEY NOT NULL, "
                      "sender_id INT NOT NULL, "
                      "receiver_id INT NOT NULL, "
                      "time_sent INT NOT NULL, "
                      "amount REAL NOT NULL"
                      "); ";

    char *error_message = 0;

    result = sqlite3_exec(db, sql, 0, 0, &error_message);

    if (result != SQLITE_OK) {
        fprintf(stderr, "Cannot execute SQL: %s\n", sqlite3_errmsg(db));
    }

    return 0;
}
