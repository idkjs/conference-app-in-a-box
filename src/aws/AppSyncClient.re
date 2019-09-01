[@bs.module] external gql: ReasonApolloTypes.gql = "graphql-tag";
[@bs.module "aws-appsync"] [@bs.new]
external makeAWSAppSyncClient:
  {
    .
    "url": Js.Nullable.t(string),
    "region": Js.Nullable.t(string),
    "auth":
      Js.Nullable.t({
        .
        "type": string,
        "jwtToken": string,
      }),
      "disableOffline": bool,
  } =>
  'a =
  "AWSAppSyncClient";

let createAWSAppSyncClient = (~url=?, ~region=?, ~auth=?, ()) => {
  let appSyncClientOptions = {
    "url": Js.Nullable.fromOption(url),
    "region": Js.Nullable.fromOption(region),
    "auth": Js.Nullable.fromOption(auth),
    "disableOffline": true,
  };
  makeAWSAppSyncClient(appSyncClientOptions);
};

let config = AppSyncConfig.appSyncConfig;
let client = token =>
  createAWSAppSyncClient(
    ~url=config.graphqlEndpoint,
    ~region=config.region,
    ~auth={"type": config.authenticationType, "jwtToken": token},
    (),
  );
// external toString: 'a => string = "%identity";
// [@bs.module "./aws-exports.js"] external config: Js.Json.t = "default";
// let config =
//   Js.Json.classify(config)
//   |> (
//     json =>
//       switch (json) {
//       | Js.Json.JSONObject(dict) => Some(dict)
//       | _ => None
//       }
//   )
//   |> Belt.Option.getWithDefault(_, Js.Dict.empty());
// let client = token =>
//   createAWSAppSyncClient(
//     ~url=
//       Belt.Option.getExn(Js.Dict.get(config, "aws_appsync_graphqlEndpoint"))
//       ->toString,
//     ~region=
//       Belt.Option.getExn(Js.Dict.get(config, "aws_appsync_region"))
//       ->toString,
//     ~auth={
//       "type":
//         Belt.Option.getExn(
//           Js.Dict.get(config, "aws_appsync_aws_appsync_authenticationType"),
//         )
//         ->toString,
//       "jwtToken": token,
//     },
//     (),
//   );