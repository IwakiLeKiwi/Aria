#ifndef MINECRAFT_INFOS
    #define MINECRAFT_INFOS

    #include "utils.hpp"
    #include <unordered_map>
    #include <iostream>

    using namespace std;

    namespace MINECRAFT {

            namespace MINECRAFT_VERSION {
                // Minecraft versions supported
                const string MIN_SUPPORTED_MINECRAFT_VERSION = "1.8";
                const string MAX_SUPPORTED_MINECRAFT_VERSION = "1.20.4";

                const string ALL_MC_SUPPORTED_VERSION[] = {
                    "1.8", "1.8.1", "1.8.2", "1.8.3", "1.8.4", "1.8.5", "1.8.6", "1.8.7", "1.8.8", "1.8.9", // 10
                    "1.9", "1.9.1", "1.9.2", "1.9.3", "1.9.4", // 5
                    "1.10", "1.10.1", "1.10.2", // 3
                    "1.11", "1.11.1", "1.11.2", // 3
                    "1.12", "1.12.1", "1.12.2", // 3
                    "1.13", "1.13.1", "1.13.2", // 3
                    "1.14", "1.14.1", "1.14.2", "1.14.3", "1.14.4", // 5
                    "1.15", "1.15.1", "1.15.2", // 3
                    "1.16", "1.16.1", "1.16.2", "1.16.3", "1.16.4", "1.16.5", // 6
                    "1.17", "1.17.1", // 2
                    "1.18", "1.18.1", "1.18.2", // 3
                    "1.19", "1.19.1", "1.19.2", "1.19.3", "1.19.4", // 5
                    "1.20", "1.20.1", "1.20.2", "1.20.3", "1.20.4" // 5
                };

                const string SUPPORTED_MC_VERSION_1_8[] = {
                    "1.8", "1.8.1", "1.8.2",
                    "1.8.3", "1.8.4", "1.8.5",
                    "1.8.6", "1.8.7", "1.8.8",
                    "1.8.9"
                };

                const string SUPPORTED_MC_VERSION_1_9[] = {
                    "1.9", "1.9.1", "1.9.2", "1.9.3", "1.9.4"
                };

                const string SUPPORTED_MC_VERSION_1_10[] = {
                    "1.10", "1.10.1", "1.10.2"
                };

                const string SUPPORTED_MC_VERSION_1_11[] = {
                    "1.11", "1.11.1", "1.11.2"
                };

                const string SUPPORTED_MC_VERSION_1_12[] = {
                    "1.12", "1.12.1", "1.12.2"
                };

                const string SUPPORTED_MC_VERSION_1_13[] = {
                    "1.13", "1.13.1", "1.13.2"
                };

                const string SUPPORTED_MC_VERSION_1_14[] = {
                    "1.14", "1.14.1", "1.14.2", "1.14.3", "1.14.4"
                };

                const string SUPPORTED_MC_VERSION_1_15[] = {
                    "1.15", "1.15.1", "1.15.2"
                };

                const string SUPPORTED_MC_VERSION_1_16[] = {
                    "1.16", "1.16.1", "1.16.2", "1.16.3", "1.16.4", "1.16.5"
                };

                const string SUPPORTED_MC_VERSION_1_17[] = {
                    "1.17", "1.17.1"
                };

                const string SUPPORTED_MC_VERSION_1_18[] = {
                    "1.18", "1.18.1", "1.18.2"
                };

                const string SUPPORTED_MC_VERSION_1_19[] = {
                    "1.19", "1.19.1", "1.19.2", "1.19.3", "1.19.4"
                };

                const string SUPPORTED_MC_VERSION_1_20[] = {
                    "1.20", "1.20.1", "1.20.2", "1.20.3", "1.20.4"
                };
            }

            namespace SERVER_JAR {

                /*
                 * FROM https://getbukkit.org
                 */
                namespace VANILLA {
                    unordered_map<string, string> VANILLA_DOWNLOAD_LINKS = {
                        {"1.8",   "https://launcher.mojang.com/mc/game/1.8/server/a028f00e678ee5c6aef0e29656dca091b5df11c7/server.jar"},
                        {"1.8.1", "https://launcher.mojang.com/mc/game/1.8.1/server/68bfb524888f7c0ab939025e07e5de08843dac0f/server.jar"},
                        {"1.8.2", "https://launcher.mojang.com/mc/game/1.8.2/server/a37bdd5210137354ed1bfe3dac0a5b77fe08fe2e/server.jar"},
                        {"1.8.3", "https://launcher.mojang.com/mc/game/1.8.3/server/163ba351cb86f6390450bb2a67fafeb92b6c0f2f/server.jar"},
                        {"1.8.4", "https://launcher.mojang.com/mc/game/1.8.4/server/dd4b5eba1c79500390e0b0f45162fa70d38f8a3d/server.jar"},
                        {"1.8.5", "https://launcher.mojang.com/mc/game/1.8.5/server/ea6dd23658b167dbc0877015d1072cac21ab6eee/server.jar"},
                        {"1.8.6", "https://launcher.mojang.com/mc/game/1.8.6/server/2bd44b53198f143fb278f8bec3a505dad0beacd2/server.jar"},
                        {"1.8.7", "https://launcher.mojang.com/mc/game/1.8.7/server/35c59e16d1f3b751cd20b76b9b8a19045de363a9/server.jar"},
                        {"1.8.8", "https://launcher.mojang.com/mc/game/1.8.8/server/5fafba3f58c40dc51b5c3ca72a98f62dfdae1db7/server.jar"},
                        {"1.8.9", "https://launcher.mojang.com/mc/game/1.8.9/server/b58b2ceb36e01bcd8dbf49c8fb66c55a9f0676cd/server.jar"},
                        
                        {"1.9",   "https://launcher.mojang.com/mc/game/1.9/server/b4d449cf2918e0f3bd8aa18954b916a4d1880f0d/server.jar"},
                        {"1.9.1", "https://launcher.mojang.com/mc/game/1.9.1/server/bf95d9118d9b4b827f524c878efd275125b56181/server.jar"},
                        {"1.9.2", "https://launcher.mojang.com/mc/game/1.9.2/server/2b95cc7b136017e064c46d04a5825fe4cfa1be30/server.jar"},
                        {"1.9.3", "https://launcher.mojang.com/mc/game/1.9.3/server/8e897b6b6d784f745332644f4d104f7a6e737ccf/server.jar"},
                        {"1.9.4", "https://launcher.mojang.com/mc/game/1.9.4/server/edbb7b1758af33d365bf835eb9d13de005b1e274/server.jar"},

                        {"1.10",   "https://launcher.mojang.com/mc/game/1.10/server/a96617ffdf5dabbb718ab11a9a68e50545fc5bee/server.jar"},
                        {"1.10.1", "https://launcher.mojang.com/mc/game/1.10.1/server/cb4c6f9f51a845b09a8861cdbe0eea3ff6996dee/server.jar"},
                        {"1.10.2", "https://launcher.mojang.com/mc/game/1.10.2/server/3d501b23df53c548254f5e3f66492d178a48db63/server.jar"},

                        {"1.11",   "https://launcher.mojang.com/mc/game/1.11/server/48820c84cb1ed502cb5b2fe23b8153d5e4fa61c0/server.jar"},
                        {"1.11.1", "https://launcher.mojang.com/mc/game/1.11.1/server/1f97bd101e508d7b52b3d6a7879223b000b5eba0/server.jar"},
                        {"1.11.2", "https://launcher.mojang.com/mc/game/1.11.2/server/f00c294a1576e03fddcac777c3cf4c7d404c4ba4/server.jar"},

                        {"1.12",   "https://launcher.mojang.com/mc/game/1.12/server/8494e844e911ea0d63878f64da9dcc21f53a3463/server.jar"},
                        {"1.12.1", "https://launcher.mojang.com/mc/game/1.12.1/server/561c7b2d54bae80cc06b05d950633a9ac95da816/server.jar"},
                        {"1.12.2", "https://launcher.mojang.com/mc/game/1.12.2/server/886945bfb2b978778c3a0288fd7fab09d315b25f/server.jar"},

                        {"1.13",   "https://launcher.mojang.com/mc/game/1.13/server/d0caafb8438ebd206f99930cfaecfa6c9a13dca0/server.jar"},
                        {"1.13.1", "https://launcher.mojang.com/v1/objects/fe123682e9cb30031eae351764f653500b7396c9/server.jar"},
                        {"1.13.2", "https://launcher.mojang.com/v1/objects/3737db93722a9e39eeada7c27e7aca28b144ffa7/server.jar"},

                        {"1.14",   "https://launcher.mojang.com/v1/objects/f1a0073671057f01aa843443fef34330281333ce/server.jar"},
                        {"1.14.1", "https://launcher.mojang.com/v1/objects/ed76d597a44c5266be2a7fcd77a8270f1f0bc118/server.jar"},
                        {"1.14.2", "https://launcher.mojang.com/v1/objects/808be3869e2ca6b62378f9f4b33c946621620019/server.jar"},
                        {"1.14.3", "https://launcher.mojang.com/v1/objects/d0d0fe2b1dc6ab4c65554cb734270872b72dadd6/server.jar"},
                        {"1.14.4", "https://launcher.mojang.com/v1/objects/d0d0fe2b1dc6ab4c65554cb734270872b72dadd6/server.jar"},

                        {"1.15",   "https://launcher.mojang.com/v1/objects/e9f105b3c5c7e85c7b445249a93362a22f62442d/server.jar"},
                        {"1.15.1", "https://launcher.mojang.com/v1/objects/4d1826eebac84847c71a77f9349cc22afd0cf0a1/server.jar"},
                        {"1.15.2", "https://launcher.mojang.com/v1/objects/4d1826eebac84847c71a77f9349cc22afd0cf0a1/server.jar"},

                        //{"1.16",   ""},
                        {"1.16.1", "https://launcher.mojang.com/v1/objects/a412fd69db1f81db3f511c1463fd304675244077/server.jar"},
                        {"1.16.2", "https://launcher.mojang.com/v1/objects/a412fd69db1f81db3f511c1463fd304675244077/server.jar"},
                        {"1.16.3", "https://launcher.mojang.com/v1/objects/f02f4473dbf152c23d7d484952121db0b36698cb/server.jar"},
                        {"1.16.4", "https://launcher.mojang.com/v1/objects/35139deedbd5182953cf1caa23835da59ca3d7cd/server.jar"},
                        {"1.16.5", "https://launcher.mojang.com/v1/objects/35139deedbd5182953cf1caa23835da59ca3d7cd/server.jar"},

                        {"1.17",   "https://launcher.mojang.com/v1/objects/0a269b5f2c5b93b1712d0f5dc43b6182b9ab254e/server.jar"},
                        {"1.17.1", "https://launcher.mojang.com/v1/objects/a16d67e5807f57fc4e550299cf20226194497dc2/server.jar"},

                        {"1.18",   "https://launcher.mojang.com/v1/objects/3cf24a8694aca6267883b17d934efacc5e44440d/server.jar"},
                        {"1.18.1", "https://launcher.mojang.com/v1/objects/125e5adf40c659fd3bce3e66e67a16bb49ecc1b9/server.jar"},
                        {"1.18.2", "https://launcher.mojang.com/v1/objects/c8f83c5655308435b3dcf03c06d9fe8740a77469/server.jar"},

                        {"1.19",   "https://launcher.mojang.com/v1/objects/e00c4052dac1d59a1188b2aa9d5a87113aaf1122/server.jar"},
                        {"1.19.1", "https://piston-data.mojang.com/v1/objects/8399e1211e95faa421c1507b322dbeae86d604df/server.jar"},
                        {"1.19.2", "https://piston-data.mojang.com/v1/objects/f69c284232d7c7580bd89a5a4931c3581eae1378/server.jar"},
                        {"1.19.3", "https://piston-data.mojang.com/v1/objects/c9df48efed58511cdd0213c56b9013a7b5c9ac1f/server.jar"},
                        {"1.19.4", "https://piston-data.mojang.com/v1/objects/8f3112a1049751cc472ec13e397eade5336ca7ae/server.jar"},
                        
                        //{"1.20",   ""},
                        {"1.20.1", "https://piston-data.mojang.com/v1/objects/84194a2f286ef7c14ed7ce0090dba59902951553/server.jar"},
                        {"1.20.2", "https://piston-data.mojang.com/v1/objects/5b868151bd02b41319f54c8d4061b8cae84e665c/server.jar"},
                        {"1.20.3", "https://piston-data.mojang.com/v1/objects/4fb536bfd4a83d61cdbaf684b8d311e66e7d4c49/server.jar"},
                        {"1.20.4", "https://piston-data.mojang.com/v1/objects/8dd1a28015f51b1803213892b50b7b4fc76e594d/server.jar"},
                        {"1.20.5", "https://piston-data.mojang.com/v1/objects/79493072f65e17243fd36a699c9a96b4381feb91/server.jar"},
                        {"1.20.6", "https://piston-data.mojang.com/v1/objects/145ff0858209bcfc164859ba735d4199aafa1eea/server.jar"}
                    };
                }

                namespace SPIGOT {

                }

                namespace BUKKIT {
                    
                }

                namespace FORGE {
                    unordered_map<string, string> FORGE_DOWNLOAD_LINKS = {
                        {"1.18",   "https://maven.minecraftforge.net/net/minecraftforge/forge/1.18-38.0.17/forge-1.18-38.0.17-installer.jar"},
                        {"1.18.1", "https://maven.minecraftforge.net/net/minecraftforge/forge/1.18.1-39.1.0/forge-1.18.1-39.1.0-installer.jar"},
                        {"1.18.2", "https://maven.minecraftforge.net/net/minecraftforge/forge/1.18.2-40.2.0/forge-1.18.2-40.2.0-installer.jar"}
                    };
                }

                namespace FABRIC {
                    
                }
            }
        }

#endif