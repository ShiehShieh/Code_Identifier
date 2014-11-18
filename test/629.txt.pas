var
  s1,s2:ansistring;
  l:longint;

procedure main;
  var
    i,j,k:longint;
  begin
    i:=1;
    j:=2;
    k:=0;
    while (i<=l)and(j<=l)and(k<l) do
      begin
        k:=0;
        while (k<l)and(s1[i+k]=s1[j+k]) do inc(k);
        if s1[i+k]>s1[j+k]
          then inc(i,k+1);
        if s1[i+k]<s1[j+k]
          then inc(j,k+1);
        if i=j
          then inc(j);
      end;
    if i>j
      then i:=j;
    s1:=copy(s1,i,l);
    writeln('Yes');
    write(s1);
    halt;

  end;

procedure work;
  var
    i,j,k:longint;
  begin
    i:=1;
    j:=1;
    k:=0;
    s1:=s1+s1;
    s2:=s2+s2;
    while (k<=2*l) do
      begin
        if s1[i+k]<s2[j+k]
          then begin
                 inc(j,k+1);
                 k:=0;
               end;
        if s1[i+k]>s2[j+k]
          then begin
                 inc(i,k+1);
                 k:=0;
               end;
        if (i>l)or(j>l)
          then break;
        if k=l
          then begin
                 main
               end;
        if s1[i+k]=s2[j+k]
          then inc(k);
      end;

  end;

begin
  readln(s1);
  readln(s2);
  l:=length(s1);
  work;
  write('No');
end.

