<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>1903070311 PHP作业</title>
    <script language="JavaScript" type="text/JavaScript">
        <!--
        function closeWINDOW()
        {
            window.location.href = "T2.HTM"; 
        }
        //-->
    </script>
</head>
<body>
    <p style="text-align: center;"><font size="30" face="楷体">您提交的数据：</font></p>
    <table border="1" cellspacing="0" bordercolor="blue" width="500" height="50" align="center">
    <tr><th>用户名</th><th><?php $username=$_POST["username"]; echo $username?></th></tr>
    <tr><th>密&emsp;码</th><th><?php $password=$_POST["password"]; echo $password?></th></tr>
    <tr><th>性&emsp;别</th>
    <th>
    <?php
    $sex = isset($_POST['sex'])? htmlspecialchars($_POST['sex']) : '';
    if($sex)
    {
        if($sex =='man') 
        {
            echo '男';
        } 
        else
        {
            echo '女';
        }
    }
    ?>
    </th></tr>

    <tr><th>职&emsp;业</th>
    <th>
    <?php 
    $work = isset($_POST['work'])? htmlspecialchars($_POST['work']) : '';
    if($work)
    {
        if($work =='student') 
        {
            echo '学生';
        } 
        else if($work =='teacher') 
        {
            echo '教师';
        }
        else
        {
            echo '职员';
        }
    }
    ?>
    </th></tr>

    <tr><th>爱&emsp;好</th>
    <th>
    <?php
    $love = isset($_POST['love'])? $_POST['love'] : '';
    if(is_array($love))
    {
        $sites = array('daze' => '发呆', 'food' => '美食', 'sport' => '运动', 'sing' => '唱歌');
        foreach($love as $val)
        {
            echo ' ';
            echo $sites[$val];
            echo ' ';
        }
    }
    ?>
    </th></tr>

    <tr><th>偶&emsp;像</th>
    <th>
    <?php
    $star = isset($_POST['star'])? htmlspecialchars($_POST['star']) : '';
    if($star)
    {
        if($star =='true')
        {
            echo '有';
        }
        else
        {
            echo '无';
        }    
    }
    ?>
    </th></tr>
    </table>
    <br><br>

    <?php
    session_start();
    $_SESSION['username']=$username;
    $_SESSION['password']=$password;
    $_SESSION['sex']=$sex;
    $_SESSION['work']=$work;
    $_SESSION['love']=$love;
    $_SESSION['sites']=$sites;
    $_SESSION['star']=$star;
    ?>

    <form align="center">
    <button type="submit"><a href="save.php">确认保存</a></button>
    &emsp;&emsp;&emsp;&emsp;
    <input type="button" value="关闭窗口" onclick="closeWINDOW()">
    </form>
</body>
</html>
