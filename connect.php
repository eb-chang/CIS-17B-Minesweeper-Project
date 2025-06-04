<?php
    define("DB_IP","localhost");
    define("DB_USER", "root");
    define("DB_PASS","");
    define("DB_DB","minesweeper_db");

    try{
        $connection = new mysqli(DB_IP, DB_USER, DB_PASS, DB_DB);

        if($connection->errno >0){
            echo "Error connecting";
        }
        // else{
        //     echo "Connected";
        // }
    }catch(Exception $e){
        debug($e);
    }

    //debug([4], "a");

    function debug(...$a){
        echo"<pre>";
        print_r($a);
        echo "</pre>";
    }

?>