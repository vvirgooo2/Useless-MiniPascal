program Autoadviser ;
// 全局变量
uses
  SysUtils;
var 
count : integer = 1;
cname : array[1..1000] of string;
credits : array[1..1000] of integer; 
conditions : array[1..1000,1..30,1..30] of string;
score : array[1..1000] of integer;

//一些临时变量，放到全局区
inputline :string;
i : integer ;
num : integer;
ch : char ; 
t : string ='' ;
len : integer  ;
orcount :integer=1;
andcount : integer=1;

//结果变量
attempt : integer = 0;
complete: integer = 0;
total : real=0;
need :integer = 0;

GPA : real;

j,k,l:integer;
flagi,flagj,flagk:integer;


function find(str: string):integer;
var
l:integer;
ret : integer=0;
begin
    for l:=1 to count do
    begin
      if((str=cname[l]) and (score[l]>0)) then ret :=1 ;
    end;
    // if(ret=1) then write('find',str);
    find:=ret;
end;


begin
  //一行行解析的方法
  readln(inputline);
  while (inputline<>'') do 
  begin
    len := length(inputline);
    //解析名字
    i:= 1 ;
    t:= '';
    while (inputline[i]<>'|') do
    begin
      t:=t+inputline[i];
      i:=i+1;
    end;
    cname[count]:=t;
    // writeln(t);
    t:='';
    i:=i+1;
    
    //解析学分
    ch := inputline[i];
    num := ord(ch)-ord('0');
    credits[count]:=num;
    // writeln(num);
    num := 0;
    i:=i+2;
    ch:=inputline[i];

    orcount:=1;
    andcount:=1;
    //有依赖
    if(ch<>'|')then
    begin
      while(1=1) do 
      begin    
        // writeln(ch);
       
        if((ch<>',') and (ch<>';') and (ch<>'|')) then
        begin
          t:=t+ch;
          // writeln(t);
        end;

        if(ch=',') then
        begin
          conditions[count][orcount][andcount]:=t;
          t:='';
          andcount:=andcount+1;
        end;

        if((ch=';') or (ch='|')) then 
        begin
          conditions[count][orcount][andcount]:=t;
          // writeln('enter');
          t:='';
          andcount := 1;
          orcount:=orcount+1;
        end;

        if(ch='|') then break;
        i:=i+1;
        ch := inputline[i];
      end;
    end;
    // writeln(conditions[count][1][1]);
    // writeln(conditions[count][1][2]);
    // writeln(conditions[count][2][1]);
    // writeln(conditions[count][2][2]);
    i:=i+1;
    if(i>len) then
    begin
      score[count]:=-1;
      count:=count+1;
      readln(inputline);
      continue;
    end;
    ch := inputline[i] ;
    if(ch='A')  then score[count]:=4
    else if(ch='B') then score[count]:=3
    else if(ch='C') then score[count]:=2
    else if(ch='D') then score[count]:=1
    else if(ch='F') then score[count]:=0
    else score[count]:=-1;
   // writeln(score[count]);
    count:=count+1;
    readln(inputline);
  end;

 // writeln(count);
  count:=count-1;
  //计算结果
  for i:=1 to count do
  begin
    if(score[i]=0) then attempt:=attempt+credits[i];
    if(score[i]>0) then 
    begin 
      attempt:=attempt+credits[i];
      complete:=complete+credits[i];
    end;
    if(score[i]<>-1) then total := total+credits[i]*score[i];
    //writeln(total);
    need:=need+credits[i];
  end;
  
  if(attempt=0) then GPA:=0
  else GPA:=total/attempt;
  need:=need-complete;
  
  writeln('GPA: ',format('%.1f',[GPA]));
  writeln('Hours Attempted: ',format('%d',[attempt]));
  writeln('Hours Completed: ',format('%d',[complete]));
  writeln('Credits Remaining: ',format('%d',[need]));
    writeln();
  writeln('Possible Courses to Take Next');


  for i:=1 to count do
  begin
    if(score[i]>0) then continue;
    flagi:=0;
    if(conditions[i][1][1]='') then flagi:=1 //没有条件
    else
    begin
      //或条件组遍历
      for j:=1 to 10 do
        begin
          if(conditions[i][j][1]='') then break; //或条件组不存在
          flagj:=1;  
          for k:=1 to 10 do 
          begin
            if(conditions[i][j][k]='') then break; //该条件不存在
            //寻找的函数
            flagk:=find(conditions[i][j][k]);
            if(flagk=0) then
            begin
              flagj:=0;
              break;
            end;
          end;
          if(flagj=1) then
          begin
            flagi:=1;
            break;
          end;


        end;
    end;
    if(flagi=1) then writeln('  ',cname[i]);
  end;
  if(need=0) then writeln('  None - Congratulations!');
end.
