program env;
var q: integer;

function a(i:integer):integer;
var x: integer;

    function b(i:integer):integer;
    begin
        b := x;
    end;

begin
    x:=b(i);
    a:=i;
end;

begin
    q:=1;
    q:=a(q);
    writeln(q);
end;
// output 1