<html>
<body>
<?php

function cocktail($array)
 {
	if (is_string($array))
	$array = str_split(preg_replace('/\s+/','',$array));
 
	do{
		$swapped = false;
		for($i=0;$i<count($array);$i++){
			if(isset($array[$i+1])){
				if($array[$i] > $array[$i+1]){
					list($array[$i], $array[$i+1]) = array($array[$i+1], $array[$i]);
					$swapped = true;
				}
			}			
		}
		if ($swapped == false) break;
		$swapped = false;
		for($i=count($array)-1;$i>=0;$i--){
			if(isset($array[$i-1])){
				if($array[$i] < $array[$i-1]) {
					list($array[$i],$array[$i-1]) = array($array[$i-1],$array[$i]);
					$swapped = true;
				}
			}
		}
	}while($swapped);
 
	return $array;
}	

function insertion($array)
{
	for($i=0;$i<count($array);$i++){
		$val = $array[$i];
		$j = $i-1;
		while($j>=0 && $array[$j] > $val){
			$array[$j+1] = $array[$j];
			$j--;
		}
		$array[$j+1] = $val;
	}
return $array;
}

function bucket($data)
{
	$minValue = $data[0];
	$maxValue = $data[0];
	$dataLength = count($data);
	for ($i = 1; $i < $dataLength; $i++)
	{
		if ($data[$i] > $maxValue)
			$maxValue = $data[$i];
		if ($data[$i] < $minValue)
			$minValue = $data[$i];
	}
	$bucket = array();
	$bucketLength = $maxValue - $minValue + 1;
	for ($i = 0; $i < $bucketLength; $i++)
	{
		$bucket[$i] = array();
	}
	for ($i = 0; $i < $dataLength; $i++)
	{
		array_push($bucket[$data[$i] - $minValue], $data[$i]);
	}
	$k = 0;
	for ($i = 0; $i < $bucketLength; $i++)
	{
		$bucketCount = count($bucket[$i]);	
		if ($bucketCount > 0)
		{
			for ($j = 0; $j < $bucketCount; $j++)
			{
				$data[$k] = $bucket[$i][$j];
				$k++;
			}
		}
	}
}

function counting($array, $min, $max)
{
  $count = array();
  for($i = $min; $i <= $max; $i++)
  {
    $count[$i] = 0;
  }
 
  foreach($array as $number)
  {
    $count[$number]++; 
  }
  $z = 0;
  for($i = $min; $i <= $max; $i++) {
    while( $count[$i]-- > 0 ) {
      $array[$z++] = $i;
    }
  }
  return $array;
}

function merge_sort($array){
	if(count($array) == 1 ) return $array;
	$mid = count($array) / 2;
    $left = array_slice($array, 0, $mid);
    $right = array_slice($array, $mid);
	$left = merge_sort($left);
	$right = merge_sort($right);
	return merge($left, $right);
}
function merge($left, $right){
	$res = array();
	while (count($left) > 0 && count($right) > 0){
		if($left[0] > $right[0]){
			$res[] = $right[0];
			$right = array_slice($right , 1);
		}else{
			$res[] = $left[0];
			$left = array_slice($left, 1);
		}
	}
	while (count($left) > 0){
		$res[] = $left[0];
		$left = array_slice($left, 1);
	}
	while (count($right) > 0){
		$res[] = $right[0];
		$right = array_slice($right, 1);
	}
	return $res;
}

function radix(&$data, $count) {
	for ($shift = 31; $shift > -1; $shift--)
	{
		$j = 0;
		for ($i = 0; $i < $count; $i++)
		{
			$move = ($data[$i] << $shift) >= 0;
			if ($shift == 0 ? !$move : $move)
				$data[$i - $j] = $data[$i];
			else
				$temp[$j++] = $data[$i];
		}
		for ($i = 0; $i < $j; $i++)
		{
			$data[($count - $j) + $i] = $temp[$i];
		}
	}
	$temp = null;
}

function gnome($array){
	$i = 1;
	$j = 2;
	while($i < count($array)){
		if ($array[$i-1] <= $array[$i]){
			$i = $j;
			$j++;
		}else{
			list($array[$i],$array[$i-1]) = array($array[$i-1],$array[$i]);
			$i--;
			if($i == 0){
				$i = $j;
				$j++;
			}
		}
	}
	return $array;
}

function shell($array)
{
	$x = round(count($array)/2);
	while($x > 0)
	{
		for($i = $x; $i < count($array);$i++){
			$temp = $array[$i];
			$j = $i;
			while($j >= $x && $array[$j-$x] > $temp)
			{
				$array[$j] = $array[$j - $x];
				$j -= $x;
			}
			$array[$j] = $temp;
		}
		$x = round($x/2.2);
	}
	return $array;
}

function selection($array)
{
for($i=0; $i<count($array)-1; $i++) {
	$min = $i;
	for($j=$i+1; $j<count($array); $j++) {
		if ($array[$j]<$array[$min]) {
			$min = $j;
		}
	}
    $array = swap_positions($array, $i, $min);
}
	return $array;
}
function swap_positions($array, $left, $right) {
	$backup_old_data_right_value = $array[$right];
	$array[$right] = $array[$left];
	$array[$left] = $backup_old_data_right_value;
	return $array;
}

function MaxHeap(&$data, $heapSize, $index) {
   $left = ($index + 1) * 2 - 1;
   $right = ($index + 1) * 2;
   $largest = 0;
   if ($left < $heapSize && $data[$left] > $data[$index])
      $largest = $left;
   else
      $largest = $index;
   if ($right < $heapSize && $data[$right] > $data[$largest])
      $largest = $right;
   if ($largest != $index)
   {
      $temp = $data[$index];
      $data[$index] = $data[$largest];
      $data[$largest] = $temp;
      MaxHeap($data, $heapSize, $largest);
   }
}
function heap(&$data, $count) {
   $heapSize = $count;
   for ($p = ($heapSize - 1) / 2; $p >= 0; $p--)
      MaxHeap($data, $heapSize, $p);
   for ($i = $count - 1; $i > 0; $i--)
   {
      $temp = $data[$i];
      $data[$i] = $data[0];
      $data[0] = $temp;
      $heapSize--;
      MaxHeap($data, $heapSize, 0);
   }
}

$array = array(3,2,4,7,0,9,1,5,8,6);
echo "Arreglo original: </br>";
echo implode (', ', $array);

echo "</br></br>Arreglo con Cocktail Sort: </br>";
echo implode(', ', cocktail($array));

echo "</br></br>Arreglo con Insertion Sort: </br>";
echo implode(', ', insertion($array));

echo "</br></br>Arreglo con Bucket Sort: </br>";
bucket($array); 
print_r($array);

echo "</br></br>Arreglo con Counting Sort: </br>";
echo implode(', ', counting($array, 0, 9));

echo "</br></br>Arreglo con Merge Sort: </br>";
echo implode(', ', merge_sort($array));

echo "</br></br>Arreglo con Radix Sort: </br>";
radix($array, 10);
print_r($array);

echo "</br></br>Arreglo con Gnome Sort: </br>";
echo implode(', ', gnome($array));

echo "</br></br>Arreglo con Shell Sort: </br>";
echo implode(', ', shell($array));

echo "</br></br>Arreglo con Selection Sort: </br>";
echo implode(', ', selection($array));

echo "</br></br>Arreglo con Heap Sort: </br>";
heap($array, 10);
print_r($array);


?>
</body>
</html>