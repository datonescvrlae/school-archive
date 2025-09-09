<html>
       <body>
              <h3>Rejestracja:</h3>
              <form method="POST">
                     <label for="username">Nazwa Uzytkownika:</label>
                     <input type="text" name="username"></input> <br>

                     <label for="password">Haslo:</label>
                     <input type="text" name="password"></input>
                     <input type="text" name="password2"></input> <br>

                     <label for="email">Email:</label>
                     <input type="email" name="email"></input> <br>

                     <input type="submit" value="Zarejestruj" name="zarejestruj"></input>
              </form> <br><br>

              <h3>Logowanie:</h3>
              <form method="POST">
                     <label for="usermail">Nazwa Uzytkownika lub Email:</label>
                     <input type="text" name="usermail"></input> <br>

                     <label for="password">Haslo:</label>
                     <input type="text" name="password"></input> <br>

                     <input type="submit" value="Zaloguj" name="zaloguj"></input>
              </form>

              <?php
                     if (isset($_POST["zarejestruj"])) {
                            $username = $_POST["username"];
                            $password = $_POST["password"];
                            $password2 = $_POST["password2"];
                            $email = $_POST["email"];

                            if ($username == "" || $password == "" || $password2 == "" || $email == "") {
                                   echo "Musisz podac wszystkie dane!";
                                   exit();
                            }

                            $connection = mysqli_connect("localhost", "root", "", "example");

                            if (mysqli_connect_error()) {
                                   echo "Blad polaczenia z baza danych! " . mysqli_connect_error();
                                   exit();
                            }

                            $query = "SELECT ID FROM users WHERE Username LIKE '" . $username . "';";
                            $result = mysqli_query($connection, $query);
                            $row = mysqli_fetch_assoc($result);

                            if (isset($row["ID"])) {
                                   echo "Uzytkownik z taka nazwa juz istnieje!";
                                   exit();
                            }

                            if ($password != $password2) {
                                   echo "Hasla musza byc takie same!";
                                   exit();
                            }

                            $hashpass = password_hash($password, PASSWORD_DEFAULT);

                            $query = "INSERT INTO users VALUES(NULL, '" . $username . "', '" . $hashpass . "', '" . $email . "');";
                            mysqli_query($connection, $query);

                            mysqli_close($connection);
                     }

                     if (isset($_POST["zaloguj"])) {
                            $usermail = $_POST["usermail"];
                            $password = $_POST["password"];

                            if ($usermail == "" || $password == "") {
                                   echo "Musisz wypelnic wszystkie pola!";
                                   exit();
                            }

                            $connection = mysqli_connect("localhost", "root", "", "example");

                            if (mysqli_connect_error()) {
                                   echo "Blad polaczenia do bazy danych! " . mysqli_connect_error();
                                   exit();
                            }

                            $query = "SELECT Password FROM users WHERE Username LIKE '" . $usermail . "';";
                            $result = mysqli_query($connection, $query);
                            $row = mysqli_fetch_assoc($result);

                            if (!isset($row["Password"])) {
                                   $query = "SELECT Password FROM users WHERE Email LIKE '" . $usermail . "';";
                                   $result = mysqli_query($connection, $query);
                                   $row = mysqli_fetch_assoc($result);

                                   if (!isset($row["Password"])) {
                                          echo "Bledna nazwa uzytkownika lub email!";
                                          exit();
                                   } 
                            }

                            $hashpass = $row["Password"];

                            if (!password_verify($password, $hashpass)) {
                                   echo "Bledne haslo!";
                                   exit();
                            }

                            echo "Zalogowano!";
                            mysqli_close($connection);
                     }
              ?>
       </body>
</html>
