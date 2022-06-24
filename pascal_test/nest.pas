program env;
var q: integer;

function a(i:integer):integer;
var 
x: integer;
y: integer;
    
    function b(i:integer):integer;
    var
    y: integer;
    begin
        y := 30;
        writeln(y);
        b := x+1;
    end;

begin
    y:=3;
    x:=3; 
    x:=b(i);
    writeln(y);
    a:=x;
end;

begin
    writeln("output:")
    q:=1;
    q:=a(q);
    writeln(q);
end.
// output 30 3 4