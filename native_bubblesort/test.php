<?php
/**
 * @author: gareth
 */

function scripted_bubblesort(array $input)
{
    // number of elements in the array
    $count = count($input);

    // loop through the array
    for ($i = 0; $i < $count; $i++)
    {
        // loop through the elements that were already processed
        for ($j = 1; $j < $count - $i; $j++)
        {
            // move on if smaller
            if ($input[$j-1] <= $input[$j]) continue;

            // swap elements
            $temp = $input[$j];
            $input[$j] = $input[$j-1];
            $input[$j-1] = $temp;
        }
    }

    // done
    return $input;
}

$count = 10000;
$x = array();
for ($i=0; $i<$count; $i++) $x[] = rand(0, 1000000);

// run the native and scripted bubblesort functions
$start = microtime(true);
$y = native_bubblesort($x);
$native = microtime(true);
$x = scripted_bubblesort($x);
$scripted = microtime(true);

// show the results
echo("Native:   ".($native - $start)." seconds\n");
echo("Scripted: ".($scripted - $native)." seconds\n");
