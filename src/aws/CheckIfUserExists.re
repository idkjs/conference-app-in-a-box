[@bs.module] external complex:Js.Json.t = "./data.json";
[@bs.module "./aws-exports.js"] external config:Js.Json.t = "default";
type awsexports = {
  aws_project_region: string,
  aws_cognito_identity_pool_id: string,
  aws_cognito_region: string,
  aws_user_pools_id: string,
  aws_user_pools_web_client_id: string,
  aws_appsync_graphqlEndpoint: string,
  aws_appsync_region: string,
  aws_appsync_authenticationType: string,
};
let decodeConfig = json:awsexports => Json.Decode.{
    aws_project_region: json |> field("aws_project_region", string),
    aws_cognito_identity_pool_id: json |> field("aws_cognito_identity_pool_id", string),
    aws_cognito_region: json |> field("aws_cognito_region", string),
    aws_user_pools_id: json |> field("aws_user_pools_id", string),
    aws_user_pools_web_client_id: json |> field("aws_user_pools_web_client_id", string),
    aws_appsync_graphqlEndpoint: json |> field("aws_appsync_graphqlEndpoint", string),
    aws_appsync_region: json |> field("aws_appsync_region", string),
    aws_appsync_authenticationType: json |> field("aws_appsync_authenticationType", string),
  };
let config = decodeConfig(config);

// [@bs.deriving abstract]
// type authT = {
//   [@bs.as "type"]
//     type_: string,
//     jwtToken: string
// };

// [@bs.deriving abstract]
// type clientOptions = {
//   url: string,
//   region: string,
//   auth:authT
// };

// [@bs.deriving abstract]
// type appSyncLinkOptions = {
//   clientOptions,
//   complexObjectsCredentials: Js.Json.t
// };
// let url = config.aws_appsync_graphqlEndpoint;
// let region = config.aws_appsync_region;
// let type_ = config.aws_appsync_authenticationType;
// let jwtToken = "BBAALKG"
module C = {

  [@bs.deriving abstract]
  type authT = {
    [@bs.as "type"]
      type_: string,
      jwtToken: string
  };

  [@bs.deriving abstract]
  type clientOptions = {
    url: string,
    region: string,
    auth:authT
  };
    let url = config.aws_appsync_graphqlEndpoint;
let region = config.aws_appsync_region;
let type_ = config.aws_appsync_authenticationType;
let jwtToken = "BBAALKG";
  let c =
      clientOptions(
        ~url,
        ~region,
        ~auth=authT(~type_, ~jwtToken),
  );
  // let _ =Js.log(c);c
};
[@bs.deriving abstract]
type appSyncLinkOptions = {
  clientOptions:C.clientOptions,
  complexObjectsCredentials: Js.Json.t
};

let a = appSyncLinkOptions(~clientOptions=C.c,~complexObjectsCredentials=complex)
let _ =Js.log(a);

