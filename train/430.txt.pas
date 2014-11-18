program T1038_4;

const
        filein='T1038_4.in';
        fileout='T1038_4.out';
        maxn=10000;

type
        Tin=longint;
        Tstr=string;
        Tarr=array[1..maxn]of Tstr;
        Tarr2=array[1..maxn]of Tin;
        Tarr3=array[1..maxn,1..190]of Tin;
        Tarr4=array[1..maxn]of boolean;

var
        j,k,l,m:Tin;
        t:boolean;
        n:Tin;
        strs:Tarr;
        len:Tarr2;
        value:Tarr3;
        pd:Tarr4;

procedure pd2(i:Tin);
begin
                for j:=len[i] downto 1 do
                        for k:=j+1 to len[i] do
                                for l:=k+1 to len[i] do
                                        if (strs[i][j]=strs[i][k])or(strs[i][k]=strs[i][l])
                                        then for m:=l+1 to len[i] do
                                                if ((strs[i][l]=strs[i][k])and(strs[i][j]=strs[i][m]))or((strs[i][j]=strs[i][k])and(strs[i][l]=strs[i][m]))
                                                        then begin
                                                                t:=true;
                                                                writeln('de1ete');
                                                                exit;
                                                        end;
                writeln('safe');
end;

procedure main;
var
        i:Tin;
begin
        readln(n);
        for i:=1 to n do
        begin
                readln(strs[i]);
                len[i]:=length(strs[i]);
                pd2(i);
        end;
end;

begin
        main;
end.
