[@bs.module "fs"] external readFileSync : (string, Js.t('a)) => string = "readFileSync";

[@bs.module "path"] external joinPaths : (string, string) => string = "join";