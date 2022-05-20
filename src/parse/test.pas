program autoadvisor;
var
    count : integer;
    cname : array[1..10000] of char;
    credits: array[1..1000] of integer;
    conditions: array[1..10000000] of char;
    score : array[1..1000] of integer;
    i,j,k,l: integer;
    num: integer;
    t : integer;
    ch : char;
    orcount : integer;
    andcount: integer;
    len :integer;
    attempt :integer;
    attemptF : real;
    complete : integer;
    total : integer;
    totalF : real;
    need : integer;
    GPA : real;
    count2 : integer;
    flagi,flagj,flagk:integer;
    namec :integer;
    funci : integer;

function outputname(y:integer):integer;
begin
    while(1=1) do begin
        ch := cname[y];
        if(ch='\0') then break;
        write(ch);
        y:=y+1;
    end;
end;

function outcon(y:integer):integer;
begin
    while(1=1) do begin
        ch := conditions[y];
        if(ch='\0') then break;
        write(ch);
        y:=y+1;
    end;
end;

function cmp(y:integer,z:integer):integer;
begin
    cmp:=1;
    while((conditions[y]<>'\0') or (cname[z]<>'\0')) do begin 
        if(conditions[y]<>cname[z]) then begin
            cmp:=0;
            break;
        end;
        y:=y+1;
        z:=z+1;
    end;
end;

function find(x:integer): integer;
begin
    find := 0;
    for l:=1 to count-1 do begin
        if((cmp(x,l*10+1)=1) and(score[l]>0)) then begin
            find := 1;
            break;
        end;
    end;
end;




begin

    count := 1;
    while (1=1) do begin
        read(ch);
        if((ch='\n') or (ch = '\0')) then break;
        len:=1;
        while(ch<>'|') do begin
            cname[count*10+len]:=ch;
            len:=len+1;
            read(ch);
        end;
        
        
        read(credits[count]);

        read(ch);
        read(ch);
        if(ch<>'|') then begin
            orcount:=1;
            andcount:=1;
            namec :=1;
            while(1=1) do begin
                if((ch<>',') and (ch<>';') and (ch<>'|')) then begin
                    conditions[count*1000+orcount*100+andcount*10+namec]:=ch;
                    namec:=namec+1;
                end;
                if(ch=',') then begin
                    andcount:=andcount+1;
                    namec:=1;
                end;
                if((ch=';') or (ch='|')) then begin
                    orcount:=orcount+1;
                    andcount :=1;
                    namec:=1;
                end;
                if(ch='|') then break;
                read(ch);
            end;
        end;
        read(ch);
        if(ch='A') then score[count] := 4;
        if(ch='B') then score[count] := 3;
        if(ch='C') then score[count] := 2;
        if(ch='D') then score[count] := 1;
        if(ch='F') then score[count] := 0;
        if(ch='\n') then begin
            score[count] := 0-1;
        end;
        else begin
            read(ch);
        end;
        count:=count+1;
    end;
    for i:=1 to count-1 do begin
        if(score[i]=0) then attempt:=attempt+credits[i];
        if(score[i]>0) then begin
            attempt := attempt + credits[i];
            complete:= complete + credits[i];
        end;
        if(score[i]>=0) then total:=total + credits[i]*score[i];
        need := need + credits[i];
    end;
    totalF := total;
    attemptF := attempt;
    if(attempt>0) then GPA:= totalF div attemptF;
    need := need - complete;
    writeln("GPA: ",GPA);
    writeln("Hours Attempted: ",attempt);
    writeln("Hours Completed: " ,complete);
    writeln("Credits Remaining: ",need);

    writeln("");
    write("Possible Courses to Take");
    writeln(" Next");
    
    j:=1;
    k:=1;
    for i:=1 to count-1 do begin
        flagi:=0;
        if(score[i]<=0) then begin
            flagi:=0;
            if(conditions[i*1000+1*100+10+1]='\0') then begin
                flagi := 1;
            end;
            else begin
                for j:=1 to 9 do begin
                    if(conditions[i*1000+j*100+10+1]='\0') then break;
                    flagj:=1;
                    for k:=1 to 9 do begin
                        if(conditions[i*1000+j*100+k*10+1]='\0') then break;
                        flagk:=find(i*1000+j*100+k*10+1);

                        if(flagk=0) then begin
                            flagj:=0;
                            break;
                        end;
                    end;
                    if(flagj=1) then begin
                        
                        flagi:=1;
                        break;
                    end;
                end;
            end;
            if(flagi=1) then begin
                write("  ");
                outputname(i*10+1);
                writeln("");
            end;
        end;
    end;
    if(need=0) then begin
        write("  None - Congratulations");
        writeln("!");
    end;
    
    


end.
