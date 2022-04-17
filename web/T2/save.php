<?php
session_start();

if($_SESSION['sex']=='man')
{
    $sex='男';
}
else
{
    $sex='女';
}

if($_SESSION['work']=='student')
{
    $work='学生';
}
elseif($_SESSION['work']=='teacher')
{
    $work='教师';
}
else
{
    $work='职员';
}

if($_SESSION['star']=='true')
{
    $star='有偶像';
}
else
{
    $star='没偶像';
}

$myfile = fopen("D:\\Data\\T2.txt", "w") or die("Unable to open file!");
fwrite($myfile, $_SESSION['username']);
fwrite($myfile, "\n");
fwrite($myfile, $_SESSION['password']);
fwrite($myfile, "\n");
fwrite($myfile, $sex);
fwrite($myfile, "\n");
fwrite($myfile, $work);
fwrite($myfile, "\n");
foreach($_SESSION['love'] as $val)
{
    fwrite($myfile, $_SESSION['sites'][$val]);
    fwrite($myfile, '   ');
}
fwrite($myfile, "\n");
fwrite($myfile, $star);
fclose($myfile);
?>

<p>保存成功！！！</p>
<button type="submit"><a href="T2.HTM">关闭窗口</a></button>