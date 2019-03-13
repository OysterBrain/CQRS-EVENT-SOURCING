<?php
function  __autoload($className) {
    require_once 'classes/'.$className.'.class.php';
}
?>
