
import { AuthOptions, NextAuthOptions } from "next-auth";
import Entra from "next-auth/providers/azure-ad"
export const authConfig : AuthOptions | NextAuthOptions = {
  pages: {
    signIn: '/authentication/sign',
  },
    providers: [
        Entra({
            clientId: process.env.AZURE_AD_CLIENT_ID as string,
            clientSecret: process.env.AZURE_AD_CLIENT_SECRET as string,
            tenantId: process.env.AZURE_AD_TENANT_ID as string,
        }),
    ],
};