macro_rules! CONTENT {
    () => {
        "macro_rules! CONTENT {{{1}    () => {{{1}        {2}{0}{2}{1}    }}{1}}}{1}{1}macro_rules! CODE {{{1}    () => {{{1}        use std::fs;{1}        let content = format!(CONTENT!(), CONTENT!(), 10 as char, 34 as char);{1}{1}        fs::write({2}Grace_kid.rs{2}, content).expect({2}Unable to write file{2});{1}    }}{1}}}{1}{1}macro_rules! START {{{1}    () => {{{1}        fn main() {{{1}            CODE!();{1}        }}{1}    }};{1}}}{1}{1}/*{1}    This is a comment{1}*/{1}START!();"
    }
}

macro_rules! CODE {
    () => {
        use std::fs;
        let content = format!(CONTENT!(), CONTENT!(), 10 as char, 34 as char);

        fs::write("Grace_kid.rs", content).expect("Unable to write file");
    }
}

macro_rules! START {
    () => {
        fn main() {
            CODE!();
        }
    };
}

/*
    This is a comment
*/
START!();