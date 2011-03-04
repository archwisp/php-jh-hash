--TEST--
Test function jh_hash() by calling it with expected arguments
--CREDITS--
Bryan C. Geraghty <bryan@ravensight.org>
--SKIPIF--
<?php if (!extension_loaded("jh")) print "skip"; ?>
--FILE--
<?php

$data = "\xde\xad\xbe\xef";

var_dump(base64_encode(jh_hash($data)));
var_dump(base64_encode(jh_hash($data, 512)));
var_dump(base64_encode(jh_hash($data, 384)));
var_dump(base64_encode(jh_hash($data, 256)));
var_dump(base64_encode(jh_hash($data, 224)));

?>
--EXPECT--
string(88) "lRxyh9X7ohte0ha0C26vnYSP4/ZeJXCRmh9CFt+06rfK7wZfg8q+K+3Zig5ik67plPiEGeNmv5opCmaNeBaK4Q=="
string(88) "lRxyh9X7ohte0ha0C26vnYSP4/ZeJXCRmh9CFt+06rfK7wZfg8q+K+3Zig5ik67plPiEGeNmv5opCmaNeBaK4Q=="
string(64) "3fxeY4SUPJDRdH4Hft+cxTj+Q1yu7NCD7vFcndEF0wtvuizCBMvUhtC/4hho9h6v"
string(44) "O2b/WvpxdjDrhqAiml2gJpd41Yyz0bd4ZgGNxRQz9qc="
string(40) "av5ome3bOJDwj9UZSYU6CphMBNdVzFKxpMwfhA=="

