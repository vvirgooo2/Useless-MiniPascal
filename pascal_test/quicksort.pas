program quicksort;
var
    n,k:longint;
    a:array[1..10002] of integer;
procedure qsort(l,r:longint);
var
    i,j,m,t:longint;
begin
    i:=l;
    j:=r;
    m:=a[(l+r)div 2];
    repeat
        while a[i]<m do i:=i+1;
        while a[j]>m do j:=j-1;
        if not(i>j) then
        begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
        i:=i+1;
        j:=j-1;
        end;
    until i>j;
    if l<j then qsort(l,j);
    if i<r then qsort(i,r);
end;
begin
    read(n);
    for k:=1 to n do
        read(a[k]);
    qsort(1,n);
    for k:=1 to n do
        writeln(a[k]);
end.